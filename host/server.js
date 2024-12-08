const http = require("http");
const server = http.createServer(function(request, response) {
    response.end("moshonka allah");
});
server.listen(3000, function() {
    console.log("bismillah");
});