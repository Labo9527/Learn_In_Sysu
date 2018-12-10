var http=require("http");
var fs=require('fs');

function sleep(n) {
  var start = new Date().getTime();
  while (true) {
    if (new Date().getTime() - start > n) {
      break;
    }
  }
}

function handleAjax(request,response) {
  setTimeout(function () {
    console.log("Yap");
    response.writeHead(200, {'Content-Type': 'text/plain'});
    response.end("" + GetRandomNum());
  }, 3000);
}

function Cs(request,response,callback) {
  callback(request,response);
  console.log("ASDD")
}

function ASY(request,response) {
  setTimeout(function(){
    console.log("Yap");
  response.writeHead(200, {'Content-Type': 'text/plain'});
  response.end(""+GetRandomNum());},3000);
}

http.createServer(function (request,response) {
    console.log(request.url)
    if (request.url == '/S4/index.html') {
      response.writeHead(200, {'Content-Type': 'text/html'});
      response.end(fs.readFileSync('index.html'));
    }
    else if (request.url == '/S4/style.css') {
      response.writeHead(200, {'Content-Type': 'text/css'});
      response.end(fs.readFileSync('style.css'));
    }
    else if (request.url == '/S4/S4.js') {
      response.writeHead(200, {'Content-Type': 'application/x-javascript'});
      response.end(fs.readFileSync('S4.js'));
    }
    else if (request.url == '/S4/assets/images/favicon.png') {
      response.writeHead(200, {'Content-Type': 'image/png'});
      response.end(fs.readFileSync('./assets/images/favicon.png'));
    }
    else if (request.url == '/S4/assets/images/atplus_white.png') {
      response.writeHead(200, {'Content-Type': 'image/png'});
      response.end(fs.readFileSync('./assets/images/atplus_white.png'));
    }
    else if (request.url == '/S4/assets/images/atplus_green.png') {
      response.writeHead(200, {'Content-Type': 'image/png'});
      response.end(fs.readFileSync('./assets/images/atplus_green.png'));
    }
    else {
      handleAjax(request,response);
      //现在问题就出在这个creatserver没有被settimeout
    }
}).listen(3000);

console.log("Server is running at 3000");

function GetRandomTime() {
  var Res=Math.floor(Math.random()*10);
  while(Res==9)
    Res=Math.floor(Math.random()*10);
  return Res%3+1;
}

function GetRandomNum() {
  return Math.floor(Math.random()*10+1);
}
