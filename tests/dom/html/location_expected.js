'use strict';

var LocationRe = require("../../../src/dom/html/locationRe");

document.location.href;

document.location.href = "http://reason.ml";

document.location.protocol;

document.location.protocol = "https";

document.location.host;

document.location.host = "reason.ml";

document.location.hostname;

document.location.hostname = "reason.ml";

document.location.port;

document.location.port = "443";

document.location.pathname;

document.location.pathname = "/reason/tools.html";

document.location.search;

document.location.search = "q=reasonml";

document.location.hash;

document.location.hash = "merlin-atom";

document.location.username;

document.location.username = "alonzo.church";

document.location.password;

document.location.password = "lambda-the-ultimate";

document.location.origin;

document.location.assign("http://reason.ml");

document.location.reload();

LocationRe.reloadWithForce(document.location);

document.location.replace("http://reason.ml");

document.location.toString();

/*  Not a pure module */
