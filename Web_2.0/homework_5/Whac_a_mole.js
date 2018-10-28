window.onload=function () {
  document.getElementById("Sand").onclick=StartGame;
  var List=document.getElementsByClassName("Game_Radio");
  setInterval(function () {
    var moles=document.getElementsByClassName('Game_Radio');
    var count=0;
    for(var i=0;i<60;i++){
      if(moles[i].style.opacity==1){
        moles[i].style.opacity=0.2;
        count++;
        number--;
      }
      if(count==5)
        break;
    }
  },1000)
  for(var i=0;i<60;i++) {
    List[i].onchange = Yes;
  }
  Time=0;
  ID=0;
  Score=0;
  ID2=0;
  number=0;
  Began=false;
}

function StartGame() {
  if(!Began) {
    ClearTime();
    Score=0;
    show();
    document.getElementById("Time_Counter").value=Time;
    document.getElementById("Status").value = "Game Began";
    ID=setInterval(CountTime,1000);
    ID2=setInterval(Appear,100);
    ID3=setInterval(show,100)
    Began=!Began;
  }
  else{
    document.getElementById("Status").value = "Game Over";
    number=0;
    var List=document.getElementsByClassName("Game_Radio");
    for(var i=0;i<60;i++) {
      List[i].style.opacity = 0.2;
    }
    clearInterval(ID);
    clearInterval(ID2);
    clearInterval(ID3);
    Time=0;
    Began=!Began;
  }
}

function show(){
  document.getElementById("Score_Counter").value=Score;
}

function Hi() {
  alert("Hello World!");
}

function CountTime(){
  document.getElementById("Time_Counter").value=Time;
  if(Time==0){
    document.getElementById("Time_Counter").value=Time;
    document.getElementById("Status").value = "Game Over";
    number=0;
    var List=document.getElementsByClassName("Game_Radio");
    for(var i=0;i<60;i++) {
      List[i].style.opacity = 0.2;
    }
    clearInterval(ID);
    clearInterval(ID2);
    clearInterval(ID3);
    Time=0;
    Began=!Began;
    return;
  }
  Time--;
}

function ClearTime() {
  Time=30;
}

function rnd(n,m){
  var random=Math.floor(Math.random()*(m-n+1)+n);
  return random;
}

function Appear() {
  number=0;
  var moles=document.getElementsByClassName('Game_Radio');
  for(var i=0;i<60;i++){
    if(moles[i].style.opacity==1) {
      number++;
    }
  }
  if(number==3)
    return;
  var num1=rnd(0,60);
  var num2=rnd(0,60);
  while(num2==num1)
    num2=rnd(0,60);
  var num3=rnd(0,60);
  while(num3==num2||num3==num1)
    var num3=rnd(0,60);
  num3=rnd(0,60);
  console.log("------------");
  console.log(number);
  console.log("------------");
  if(number<=0)
  moles[num1].style.opacity="1";
  if(number<=1)
  moles[num2].style.opacity="1";
  if(number<=2)
  moles[num3].style.opacity="1";
  number=3;
}

function Yes(Sample) {
  if(Sample.target.style.opacity=="1"){
    Score+=1;
    Sample.target.style.opacity="0.2";
    number-=1;
  }
  else{
    Score-=1;
  }
  Sample.target.checked=false;
}
