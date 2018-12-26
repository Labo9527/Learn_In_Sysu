var express = require('express');
var router = express.Router();

var check=require('../public/javascripts/check');

var users={};

var Flag=true;

//var userdb=require('../db');

var DBUrl='mongodb://localhost:27017/data';


var mongoose=require('mongoose');
mongoose.Promise=global.Promise;

var conn=mongoose.connection.openUri(DBUrl);

var User=new mongoose.Schema({
  username: String,
  password: String,
  code: String,
  phone: String,
  mail: String
})

var myModel=conn.model('user',User);

mongoose.connection.on('connected', function () {
  console.log('Mongoose connection open to ' + DBUrl);
});

mongoose.connection.on('error',function (err) {
  console.log('Mongoose connection error: ' + err);
});

mongoose.connection.on('disconnected', function () {
  console.log('Mongoose connection disconnected');
});

var SeesionId=0;
var Us;

/* GET home page. */

router.get('/detail',function (req,res,next) {
  if(SeesionId!==0) {
    req.session.user=Us;
    res.render('detail', {title: '用户详情', user: req.session.user});
  }
  else
    res.render('signin',{user:{username:req.body.username,password:''},whathappen: "请登录"});
})

router.get('/signin',function (req,res,next) {
  res.render('signin',{title:'用户登录',user:{}});
})

router.get('/',function (req,res,next) {
  console.log(SeesionId);
  if(SeesionId!==0)
    req.session.user=Us;
  req.session.user?res.redirect('/detail'):res.redirect('/signin');
})

/*
router.all('*', function (req, res, next) {
 req.session.user ? next() : res.redirect('/register');
});
*/
router.get('/register', function(req, res, next) {
  //res.send("Hello Wold!");
  res.render('index', { title: '用户注册',user:{} });
});

router.post('/signin',function (req,res,next) {
  console.log(req.body);
  myModel.findOne({username:req.body.username,password: req.body.password},
    function (err,user) {
    console.log(user);
    if(err) throw err;
      if(user){
        Us=user;
        req.session.user=user;
        SeesionId=1;
        res.redirect('/detail');
      }
      else{
        res.render('signin',{user:{username:req.body.username,password:''},whathappen: "用户或密码错误"});
      }
    });
})

router.post('/detail',function (req,res,next) {
  console.log("Yes");
  SeesionId=0;
  req.session.user={};
  res.redirect('/signin');
})

router.post('/register', function (req, res, next) {
  var user=req.body;
  //console.log(user);
  //console.log(users);
  if (checkUnique(user)) {
    //console.log(user);
    //console.log(users);
    users[user.username] = user;
    req.session.user = users[user.username] = user;
    //console.log(req.sessionID)
    SeesionId=req.sessionID;
    Us=req.session.user;
    //console.log(req.session.user);
    var Enity=new myModel({
      username:user.username,
      password:user.password,
      code:user.code,
      phone:user.phone,
      mail:user.mail
    })
    Enity.save(function(err,user){
        if(err) throw err;
        console.log("写入成功");
    });


    res.redirect(302,'/detail');
  }
  else {
    console.log("asd");
    res.render('index', {title: '注册', user: user, whathappen: "用户信息已存在或者用户格式不正确"});
  }
});


module.exports = router;

JAX=function(user){
  myModel.findOne({username:user.username},
    function (err,user) {
      //console.log(user);
      if(err) throw err;
      if(user){
        Flag=false;
        console.log("变价发了");
      }
      else{
        console.log("在这：");
        Flag=true;
      }
    });
}

checkUnique=function(user){
  for(var attr in user){
    if(check.isRight(attr,user[attr])==false)
      return false;
    if(check.isUnique(users,user,attr)==false) {
      //console.log(users);
      //console.log(user);
      //console.log(attr);
      return false;
    }
  }
  Flag=true;
  myModel.findOne({username:user.username},
    function (err,user) {
      //console.log(user);
      if(err) throw err;
      if(user){
        Flag=false;
        console.log("变价发了");
      }
      else{
        console.log("在这：");
        Flag=true;
      }
    });
//  setTimeout(function () {
    return Flag;
// },100)
};
