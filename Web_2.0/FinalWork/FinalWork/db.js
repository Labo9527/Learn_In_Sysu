var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("data");
  var myobj = {
    username: 'yang',
    password: '123123',
    code: '17343140',
    phone: '15126548154',
    mail: '2495988865@qq.com'
  };
  dbo.collection("userInfor").insertOne(myobj, function(err, res) {
    if (err) throw err;
    console.log("文档插入成功");
    db.close();
  });
});
