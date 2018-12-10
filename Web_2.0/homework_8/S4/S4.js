window.onload=function () {
  Pressed=[true,true,true,true,true];
  Res=false;
  var Spans=document.getElementsByClassName("unread");
  for(var i=0;i<Spans.length;i++){
    Spans[i].style.visibility='hidden';
    console.log(2);
  }
  document.getElementById("at").onclick=function(){
    var SX="";
    while(true){
      var Ran=Math.floor(Math.random()*100)%5;
      if(SX.length==5)
        break;
      if(Ran==0&&SX.indexOf("A")==-1){
        SX=SX+"A";
      }
      else if(Ran==1&&SX.indexOf("B")==-1){
        SX=SX+"B";
      }
      else if(Ran==2&&SX.indexOf("C")==-1){
        SX=SX+"C";
      }
      else if(Ran==3&&SX.indexOf("D")==-1){
        SX=SX+"D";
      }
      else if(Ran==4&&SX.indexOf("E")==-1){
        SX=SX+"E";
      }
    }
    document.getElementById("Order").innerText=SX;
    var A=SX.charAt(0);
    var B=SX.charAt(1);
    var C=SX.charAt(2);
    var D=SX.charAt(3);
    var E=SX.charAt(4);
    var YL="ABCDE";
    //把Pressed[1]改成Pressed[SX.indexof(A)
    var TA=setInterval(function () {
      if(1){
        document.getElementById(A).click();
        console.log("S");
        clearInterval(TA);
      }
    },100);
    var TB=setInterval(function () {
      if(!Pressed[YL.indexOf(A)]&&Pressed[YL.indexOf(B)]) {
        document.getElementById(B).click();
        console.log("Heer");
        clearInterval(TB);
      }
    },100)

    var TC=setInterval(function () {
      if(!Pressed[YL.indexOf(A)]&&!Pressed[YL.indexOf(B)]&&Pressed[YL.indexOf(C)]) {
        document.getElementById(C).click();
        console.log("SDA");
        clearInterval(TC);
      }
    },100)

    var TD=setInterval(function () {
      if(!Pressed[YL.indexOf(A)]&&!Pressed[YL.indexOf(B)]&&Pressed[YL.indexOf(D)]&&!Pressed[YL.indexOf(C)]) {
        document.getElementById(D).click();
        clearInterval(TD);
      }
    },100)

    var TE=setInterval(function () {
      if(!Pressed[YL.indexOf(A)]&&!Pressed[YL.indexOf(B)]&&!Pressed[YL.indexOf(C)]&&!Pressed[YL.indexOf(D)]&&Pressed[YL.indexOf(E)]) {
        document.getElementById(E).click();
        clearInterval(TE);
      }
    },100)

    var TH=setInterval(function (){
      if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4]) {
        console.log('Yap');
        document.getElementById("info-bar").click();
        clearInterval(TH);
      }}
    ,100);
}
  document.getElementById("Help").onmouseout=function(){
    Pressed=[true,true,true,true,true];
    Res=false;
    document.getElementById("A").style.backgroundColor='#303F9F';
    document.getElementById("B").style.backgroundColor='#303F9F';
    document.getElementById("C").style.backgroundColor='#303F9F';
    document.getElementById("D").style.backgroundColor='#303F9F';
    document.getElementById("E").style.backgroundColor='#303F9F';
    document.getElementById('Ax').style.visibility = 'hidden';
    document.getElementById('Bx').style.visibility = 'hidden';
    document.getElementById('Cx').style.visibility = 'hidden';
    document.getElementById('Dx').style.visibility = 'hidden';
    document.getElementById('Ex').style.visibility = 'hidden';
    document.getElementById("info-bar").style.backgroundColor='gray';
    document.getElementById("Result").innerText='';
  }
  document.getElementById("info-bar").onclick=function(){
    console.log(989)
    if(Pressed[0]||Pressed[1]||Pressed[2]||Pressed[3]||Pressed[4]||Res)
      return;
    var A,B,C,D,E;
    console.log(12333);
    A=parseInt(document.getElementById("Ax").innerText);
    B=parseInt(document.getElementById("Bx").innerText);
    C=parseInt(document.getElementById("Cx").innerText);
    D=parseInt(document.getElementById("Dx").innerText);
    E=parseInt(document.getElementById("Ex").innerText);
    document.getElementById("Result").innerText=A+B+C+D+E;
    document.getElementById("info-bar").style.backgroundColor='gray';
    Res=true;
  }
  document.getElementById("A").onclick=function () {
    if(document.getElementById("A").style.backgroundColor=='gray')
      return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Ax').style.visibility = 'visible';
    document.getElementById("Ax").innerText = '...';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    xmlhttp.onreadystatechange=function () {
      if (xmlhttp.status == 200) {
        document.getElementById("Ax").innerText = xmlhttp.responseText;
        if(Pressed[1])
          document.getElementById("B").style.backgroundColor='#303F9F';
        if(Pressed[2])
          document.getElementById("C").style.backgroundColor='#303F9F';
        if(Pressed[3])
          document.getElementById("D").style.backgroundColor='#303F9F';
        if(Pressed[4])
          document.getElementById("E").style.backgroundColor='#303F9F';
        document.getElementById("A").style.backgroundColor='gray';
        Pressed[0]=false;
        if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4])
          document.getElementById("info-bar").style.backgroundColor="#303F9F";
      }
    }
    xmlhttp.open("GET", true);
    xmlhttp.send();
  }

  document.getElementById("B").onclick=function () {
    if(document.getElementById("B").style.backgroundColor=='gray')
      return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Bx').style.visibility = 'visible';
    document.getElementById("Bx").innerText = '...';
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    xmlhttp.onreadystatechange=function () {
      if (xmlhttp.status == 200) {
        document.getElementById("Bx").innerText = xmlhttp.responseText;
        if(Pressed[0])
          document.getElementById("A").style.backgroundColor='#303F9F';
        if(Pressed[2])
          document.getElementById("C").style.backgroundColor='#303F9F';
        if(Pressed[3])
          document.getElementById("D").style.backgroundColor='#303F9F';
        if(Pressed[4])
          document.getElementById("E").style.backgroundColor='#303F9F';
        document.getElementById("B").style.backgroundColor='gray';
        Pressed[1]=false;
        if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4])
          document.getElementById("info-bar").style.backgroundColor="#303F9F";
      }
    }
    xmlhttp.open("GET", true);
    xmlhttp.send();
  }

  document.getElementById("C").onclick=function () {
    if(document.getElementById("C").style.backgroundColor=='gray')
      return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Cx').style.visibility = 'visible';
    document.getElementById("Cx").innerText = '...';
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    xmlhttp.onreadystatechange=function () {
      if (xmlhttp.status == 200) {
        document.getElementById("Cx").innerText = xmlhttp.responseText;
        if(Pressed[0])
          document.getElementById("A").style.backgroundColor='#303F9F';
        if(Pressed[1])
          document.getElementById("B").style.backgroundColor='#303F9F';
        if(Pressed[3])
          document.getElementById("D").style.backgroundColor='#303F9F';
        if(Pressed[4])
          document.getElementById("E").style.backgroundColor='#303F9F';
        document.getElementById("C").style.backgroundColor='gray';
        Pressed[2]=false;
        if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4])
          document.getElementById("info-bar").style.backgroundColor="#303F9F";
      }
    }
    xmlhttp.open("GET", true);
    xmlhttp.send();
  }

  document.getElementById("D").onclick=function () {
    if(document.getElementById("D").style.backgroundColor=='gray')
      return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Dx').style.visibility = 'visible';
    document.getElementById("Dx").innerText = '...';
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    xmlhttp.onreadystatechange=function () {
      if (xmlhttp.status == 200) {
        document.getElementById("Dx").innerText = xmlhttp.responseText;
        if(Pressed[0])
          document.getElementById("A").style.backgroundColor='#303F9F';
        if(Pressed[1])
          document.getElementById("B").style.backgroundColor='#303F9F';
        if(Pressed[2])
          document.getElementById("C").style.backgroundColor='#303F9F';
        if(Pressed[4])
          document.getElementById("E").style.backgroundColor='#303F9F';
        document.getElementById("D").style.backgroundColor='gray';
        Pressed[3]=false;
        if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4])
          document.getElementById("info-bar").style.backgroundColor="#303F9F";
      }
    }
    xmlhttp.open("GET", true);
    xmlhttp.send();
  }

  document.getElementById("E").onclick=function () {
    if(document.getElementById("E").style.backgroundColor=='gray')
      return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Ex').style.visibility = 'visible';
    document.getElementById("Ex").innerText = '...';
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    xmlhttp.onreadystatechange=function () {
      if (xmlhttp.status == 200) {
        document.getElementById("Ex").innerText = xmlhttp.responseText;
        if(Pressed[0])
          document.getElementById("A").style.backgroundColor='#303F9F';
        if(Pressed[1])
          document.getElementById("B").style.backgroundColor='#303F9F';
        if(Pressed[2])
          document.getElementById("C").style.backgroundColor='#303F9F';
        if(Pressed[3])
          document.getElementById("D").style.backgroundColor='#303F9F';
        document.getElementById("E").style.backgroundColor='gray';
        Pressed[4]=false;
        if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4])
          document.getElementById("info-bar").style.backgroundColor="#303F9F";
      }
    }
    xmlhttp.open("GET", true);
    xmlhttp.send();
  }
}
