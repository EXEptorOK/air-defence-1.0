const fs = require("fs");
const http = require("http");
const path = require("path");
const express = require("express");

const server = express();
server.use("/", function(request, response, next) {
    const now = new Date();
    const hour = now.getHours();
    const minutes = now.getMinutes();
    const seconds = now.getSeconds();
    const data = `${hour}:${minutes}:${seconds} ${request.method} ${request.url} ${request.get("user-agent")}`;
    console.log(data);
    fs.appendFile("server.log", data + "\n", function(error){
        if(error) return console.log(error); // если возникла ошибка    
        console.log("Запись файла завершена");
    });
    next();
});

server.get("/", function(_, response) {
    response.send("Hello");
});

server.use(express.static("../frontend"));

server.listen(3000, function() {
    console.log("bismillah");
});