/*
JS侵入CSS的话一堆BUG
还是不要侵入式的好
 */

window.onload=function () {
  //Reset();
  Time=0;
  Began=false;
  setInterval(function () {
    if(Began){
      document.getElementById("Answer").innerText="Your Step:"+Step+" Time: "+Time+"s";
      Time++;
    }
    else{
      document.getElementById("Answer").innerText="Enjoy your time!";
    }
  },1000)
  document.getElementById("Answer").innerText="Enjoy your time!";
  Initial();
  Step=0;
}

function rnd(n,m){
  var random=Math.floor(Math.random()*(m-n+1)+n);
  return random;
}

function Reset(){
  Time=0;
  Step=0;
  Began=false;
  document.getElementById("Answer").innerText="Enjoy your time!";
  for(var i=0;i<16;i++){
    var Part=document.getElementById("ImgPosition"+i);
    Part.className="BoxPosition"+i;
  }
}

function Start() {
  Time=0;
  Step=0;
  Began=true;
  document.getElementById("Answer").innerText="Your Step:"+Step+"               Time: "+Time+"s";
  while(true) {
    var array=new Array();
    for(var i=0;i<16;i++)
      array[i]=1;
    console.log(array);
    for (var i = 0; i < 16; i++) {
      var Part = document.getElementById("ImgPosition" + i);
      var K = rnd(0, 15);
      while(array[K]==0){
        K=rnd(0,15);
      }
      array[K]=0;
      Part.className="BoxPosition"+K;
    }
    if(Check())
      return;
  }
}

function Check() {
  var Res=0;
  for(var i=0;i<16;i++){
    for(var j=0;j<i;j++){
      var part1=document.getElementById("ImgPosition"+i);
      var part2=document.getElementById("ImgPosition"+j);
      if(part2.style.top>part1.style.top)
        Res++;
      else if(part2.style.top==part1.style.left&&part2.style.left>part1.style.left)
        Res++;
    }
  }
  return Res%2==0;
}

function Initial() {
  document.getElementById("Restart").onclick=Start;
  document.getElementById("RRstart").onclick=Reset;
  var Box=document.getElementById("Picture");
  for(var i=0;i<16;i++){
    var Child=document.createElement("div");
    Child.id="ImgPosition"+i;
    Child.className="BoxPosition"+i;
    Child.style.height="88.5px";
    Child.style.width="88.5px";
    Child.classList.add("Part");
    Child.style.position="absolute";
    Child.style.transitionDuration="0.2s";
    Child.addEventListener("click",Click);
    Box.appendChild(Child);
  }
}

function Click() {
  Began=true;
  Step++;
  var Tar=event.srcElement;
  for(var i=0;i<16;i++){
    var Part = document.getElementsByClassName("BoxPosition"+i)[0];
    if(Tar==Part){
      if(i>3){
        var Te=document.getElementsByClassName("BoxPosition"+(i-4))[0];
        if(Te.id=="ImgPosition15"){
          var temp=Te.className;
          Te.className=Tar.className;
          Tar.className=temp;
          if(Success()){
            console.log("you win");
            document.getElementById("Answer").innerText="You Win!";
          }
          else{
            document.getElementById("Answer").innerText="Your Step:"+Step+" Time: "+Time+"s";
          }
          return;
        }
      }
      if(i%4!=0){
        var Te=document.getElementsByClassName("BoxPosition"+(i-1))[0];
        if(Te.id=="ImgPosition15"){
          var temp=Te.className;
          Te.className=Tar.className;
          Tar.className=temp;
          if(Success()){
            console.log("you win");
            document.getElementById("Answer").innerText="You Win!";
          }
          else{
            document.getElementById("Answer").innerText="Your Step:"+Step+" Time: "+Time+"s";
          }
          return;
        }
      }
      if(i%4!=3){
        var Te=document.getElementsByClassName("BoxPosition"+(i+1))[0];
        if(Te.id=="ImgPosition15"){
          var temp=Te.className;
          Te.className=Tar.className;
          Tar.className=temp;
          if(Success()){
            console.log("you win");
            document.getElementById("Answer").innerText="You Win!";
          }
          else{
            document.getElementById("Answer").innerText="Your Step:"+Step+" Time: "+Time+"s";
          }
          return;
        }
      }
      if(i<12){
        var Te=document.getElementsByClassName("BoxPosition"+(i+4))[0];
        if(Te.id=="ImgPosition15"){
          var temp=Te.className;
          Te.className=Tar.className;
          Tar.className=temp;
          if(Success()){
            console.log("you win");
            document.getElementById("Answer").innerText="You Win!";
          }
          else{
            document.getElementById("Answer").innerText="Your Step:"+Step+" Time: "+Time+"s";
          }
          return;
        }
      }
    }
  }
}

function Success() {
  for(var i=0;i<16;i++){
    var part=document.getElementById("ImgPosition"+i);
    if(part.className!=("BoxPosition"+i)) {
      console.log("you lose");
      return false;
    }
  }
  return true;
}
