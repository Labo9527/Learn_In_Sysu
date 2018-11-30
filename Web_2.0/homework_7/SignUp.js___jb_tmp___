var http=require("http");
var url=require("url");
var query=require("querystring");
var jade=require('jade');
var fs=require('fs');
var check=require('./check')
var users={};

var counter=0;

parseUser=function (string) {
  var par=string.match(/username=(.+)&code=(.+)&phone=(.+)&mail=(.+)/i);
  //console.log(par)
  var user={};
  user.username=par[1];
  user.code=par[2];
  user.phone=par[3];
  /*for(var i=0;i<par[4].length-2;i++){
    if(par[4].charAt(i)=='%'&&par[4].charAt(i+1)=='4'&&par[4].charAt(i+2)=='0'){

    }
  }*/
  //par[4].replace("%40","@");
  user.mail=par[4].replace("%40","@");
  console.log(user);
  return user;
}

var sever=http.createServer(function (request,response) {
  //console.log(counter);
  counter++;
  console.log(request.url);
  if(request.url=='/Detail.css'){
    console.log("Detail.css");
    response.writeHead(200,{'Content-Type':'text/css'});
    response.end(fs.readFileSync('Detail.css'))
  }
  else if(request.url=='/Index.css'){
    //console.log("SignUp.css");
    response.writeHead(200,{'Content-Type':'text/css'});
    response.end(fs.readFileSync('Index.css'));
  }
  else if(request.url=='/sha_bg_01.png'){
    response.writeHead(200,{'Content-Type':'image/png'});
    response.end(fs.readFileSync('sha_bg_01.png'));
  }
  else if(request.url=='/Index.js'){
    response.writeHead(200,{'Content-Type':'application/x-javascript'});
    response.end(fs.readFileSync('Index.js'));
  }
  else if(request.url=='/check.js'){
    response.writeHead(200,{'Content-Type':'application/x-javascript'});
    response.end(fs.readFileSync('check.js'));
  }
  if(request.method==="POST") {
    //console.log("1");
    register(request,response);
  }
  else{
    ShowPage(request,response);
    //console.log("2");
  }
}).listen(8000);

console.log("Sever is running at 8000");

register=function(request,response){
  request.on("data",function (chunk) {
    console.log(chunk.toString());
    var user = parseUser(chunk.toString());
    if(checkUnique(user)==false){
      response.writeHead(200,{'Content-Type':'text/html'})
      var html=jade.renderFile("Index.jade",{"whathappen":"用户信息已存在或者用户格式不正确"});
      response.end(html);
    }
    users[user.username]=user;
    response.writeHead(301,{'Location':"?username="+user.username});
    response.end();
  });
};

checkUnique=function(user){
  for(var attr in user){
    if(check.isRight(attr,user[attr])==false)
      return false;
    if(check.isUnique(users,attr,user)==false)
      return false;
  }
};

ShowPage=function(request,response){
  var username=parse(request);
  if(!username||!users[username]){
    response.writeHead(200,{'Content-Type':'text/html'})
    var html=jade.renderFile("Index.jade");
    response.end(html);
  }
  else{
    response.writeHead(200,{'Content-Type':'text/html'})
    var html=jade.renderFile("Detail.jade",users[username]);
    response.end(html);
  }
}

parse=function (request) {
  return query.parse(url.parse(request.url).query).username;
}


