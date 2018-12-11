window.onload=function () {

  setTimeout(function () {
    console.log(1231);
  },3000);

  setTimeout(function () {
    console.log(312);
  },1000)

  Pressed=[true,true,true,true,true];
  Res=false;
  var Spans=document.getElementsByClassName("unread");
  for(var i=0;i<Spans.length;i++){
    Spans[i].style.visibility='hidden';
    console.log(2);
  }
  /*
  document.getElementById("button").onmouseenter=function(){
    var T=document.getElementById("info-bar");
    T.style.position="absolute";
    T.style.width="130px";
    T.style.height="130px";
    T.style.bottom="150px";
    T.style.left="25px";
    T.style.borderRadius="50%";
    T.style.backgroundColor="#7E7E7E";
    T.style.opacity="1";
  };
  */
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
    if(document.getElementById("A").style.backgroundColor=='gray'){

    }
      //return;
    document.getElementById('Ax').style.visibility = 'visible';
    document.getElementById("Ax").innerText = '...';
    /*
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    */
    var xmlhttp=new XMLHttpRequest();
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
    xmlhttp.open("GET","Digit1", true);
      xmlhttp.send();
  }

  document.getElementById("B").onclick=function () {
    if(document.getElementById("B").style.backgroundColor=='gray'){

    }
      //return;
    document.getElementById('Bx').style.visibility = 'visible';
    document.getElementById("Bx").innerText = '...';
    /*
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    */
    var xmlhttp=new XMLHttpRequest();
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
    xmlhttp.open("GET","Digit2", true);
    xmlhttp.send();
  }

  document.getElementById("C").onclick=function () {
    if(document.getElementById("C").style.backgroundColor=='gray'){

    }
      //return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Cx').style.visibility = 'visible';
    document.getElementById("Cx").innerText = '...';
    /*
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    */
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
    xmlhttp.open("GET","Digit3", true);
    xmlhttp.send();
    console.log("请求已发出");
  }

  document.getElementById("D").onclick=function () {
    if(document.getElementById("D").style.backgroundColor=='gray'){

    }
      //return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Dx').style.visibility = 'visible';
    document.getElementById("Dx").innerText = '...';
    /*
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("E").style.backgroundColor='gray';
    */
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
    xmlhttp.open("GET","Digit4", true);
    xmlhttp.send();
  }

  document.getElementById("E").onclick=function () {
    if(document.getElementById("E").style.backgroundColor=='gray'){

    }
      //return;
    var xmlhttp=new XMLHttpRequest();
    document.getElementById('Ex').style.visibility = 'visible';
    document.getElementById("Ex").innerText = '...';
    /*
    document.getElementById("A").style.backgroundColor='gray';
    document.getElementById("B").style.backgroundColor='gray';
    document.getElementById("C").style.backgroundColor='gray';
    document.getElementById("D").style.backgroundColor='gray';
    */
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
    console.log("E请求已发出");
    xmlhttp.open("GET","Digit5", true);
    xmlhttp.send();
  }
  document.getElementById("button").classList.add("hover");
  document.getElementById("control-ring").classList.add("hover");
  autoClick();
}

autoClick=function () {
  document.getElementById("A").click();
  document.getElementById("B").click();
  document.getElementById("C").click();
  document.getElementById("D").click();
  document.getElementById("E").click();

  var TH=setInterval(function () {
    if(!Pressed[0]&&!Pressed[1]&&!Pressed[2]&&!Pressed[3]&&!Pressed[4]) {
      document.getElementById("info-bar").click();
      clearInterval(TH);
    }
  },100)

  //document.getElementById("B").click();
  //document.getElementById("C").click();
  //document.getElementById("D").click();
  //document.getElementById("E").click();
  /*
  if(Pressed[0])
      document.getElementById("A").click();
  if(Pressed[1])
      document.getElementById("B").click();
  if(Pressed[2])
      document.getElementById("C").click();
  if(Pressed[3])
      document.getElementById("D").click();
  if(Pressed[4])
      document.getElementById("E").click();
   */
}

