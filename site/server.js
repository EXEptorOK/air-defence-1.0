const fs = require("fs");
const http = require("http");
const path = require("path");
const express = require("express");

const server = express();
server.use(express.static("frontend"))
server.listen(3000, function() {
    console.log("bismillah");
});