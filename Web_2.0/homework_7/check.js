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
    }
  },

  checkUsername:function (string) {
      this.exam.username.flag=/^[a-zA-Z][a-zA-Z0-9_]{5,17}$/.test(string);
      //console.log("string:",string);
      //console.log(this.exam.username.flag);
      return this.exam.username.flag;
  },

  checkCode:function (string) {
      this.exam.code.flag=/^[1-9]\d{7}$/.test(string);
      return this.exam.code.flag;
  },

  checkPhone:function(string){
      this.exam.phone.flag=/^[1-9]\d{10}$/.test(string);
      return this.exam.phone.flag;
  },

  checkMail:function(string){
      this.exam.mail.flag=/^[0-9a-zA-Z_\-]+@([a-zA-Z_\-]+\.)+[a-zA-Z]{2,4}$/.test(string);
      console.log(string);
      return this.exam.mail.flag;
  },

  isRight:function (name,value){
    var K=name[0].toUpperCase()+name.slice(1,name.length);
    console.log("K:",K);
    console.log("Value:",value);
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
  },

  getMessage:function(name){
    return this.exam[name].message;
  },

  isUnique:function (registry,user,attr) {
    for(var key in registry){
      if(registry[key][attr]==user[attr])
        return false;
    }
    return true;
  }
}

if(typeof module == 'object'){
  module.exports=check;
}
