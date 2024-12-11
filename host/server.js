const fs = require("fs");
const http = require("http");

const server = http.createServer(function(request, response) {
    if (request.url === "/user") {
        let data = "";
        request.on("data", chunk => {
            data += chunk;
        });
        request.on("end", () => {
            console.log(data);
            response.end("Данные успешно получены");
        });
    }
    else {
        fs.readFile("../site/index.html", (error, data) => response.end(data));
    }
});
server.listen(3000, function() {
    console.log("bismillah");
});