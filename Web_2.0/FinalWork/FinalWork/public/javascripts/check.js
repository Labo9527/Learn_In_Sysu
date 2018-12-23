var check={
  exam:{
    username:{
      flag:false,
      Message:'6~18位英文字母，数字或下划线，必须以英文字母开头'
    },
    code:{
      flag:false,
      Message:'8位数字，不能以0开头'
    },
    phone:{
      flag:false,
      Message:'11位数字，不能以0开头'
    },
    mail:{
      flag:false,
      Message:'邮箱非法'
    },
    password:{
      flag:false,
      Message:"密码为6~12位数字、大小写字母、中划线、下划线"
    },
    'repeat-password':{
      flag:false,
      Message:"重复密码不一致"
    }

  },

  checkUsername:function (string) {
    this.exam.username.flag=/^[a-zA-Z][a-zA-Z0-9_]{5,17}$/.test(string);
    //console.log("string:",string);
    //console.log(this.exam.username.flag);
    console.log("1:"+this.exam.username.flag);
    return this.exam.username.flag;
  },

  checkPassword:function(string){
    //console.log("yap:",string);
    this.password=string;
    return this.exam.password.flag=/[a-zA-Z0-9_\-]{6,12}$/g.test(string);
  },

  'checkRepeat-password':function(string){
    return this.exam["repeat-password"].flag=string==this.password;
  },

  checkCode:function (string) {
    this.exam.code.flag=/^[1-9]\d{7}$/.test(string);
    console.log("1:"+this.exam.username.flag);
    return this.exam.code.flag;
  },

  checkPhone:function(string){
    this.exam.phone.flag=/^[1-9]\d{10}$/.test(string);
    console.log("1:"+this.exam.username.flag);
    return this.exam.phone.flag;
  },

  findFormatErrors:function(user){
    var errorMessages=[];
    for(var key in user){
      if(user.hasOwnProperty(key)){
        if(!check.isRight(key,user[key])) errorMessages.push(check.exam[key].Message);
      }
    }
    errorMessages.length>0?new Error(errorMessages.join('<br />')):null;
  },

  checkMail:function(string){
    this.exam.mail.flag=/^[0-9a-zA-Z_\-]+@([a-zA-Z_\-]+\.)+[a-zA-Z]{2,4}$/.test(string);
    //console.log(string);
    console.log("1:"+this.exam.username.flag);
    return this.exam.mail.flag;
  },

  isRight:function (name,value){
    var K=name[0].toUpperCase()+name.slice(1,name.length);
    //console.log("K:",K);
    //console.log("Value:",value);
    return this["check"+K](value);
  },

  allRight:function () {
    if(!this.exam.username.flag)
      return false;
    if(!this.exam.code.flag)
      return false;
    if(!this.exam.phone.flag)
      return false;
    if(!this.mail.flag)
      return false;
    if(!this.exam.password.flag)
      return false;
    if((typeof window !== 'object')|| !this.exam['repeat-password'].flag)
      return false;
    return true;
  },

  getMessage:function(name){
    return this.exam[name].message;
  },

  isUnique:function (registry,user,attr) {
    for(var key in registry){
      if(registry[key][attr]==user[attr]&&attr!='password'&&attr!='repeat-password') {
        console.log(attr);
        console.log(registry[key][attr]);
        console.log(user[attr]);
        return false;
      }
    }
    return true;
  }
}

if(typeof module == 'object'){
  module.exports=check;
}

function capCamelize(string) {
  return string.split(/[_\-]/).map(capitalize).join('');
}

function capitalize(string) {
  return string[0].toUpperCase()+string.slice(1,string.length);
}
