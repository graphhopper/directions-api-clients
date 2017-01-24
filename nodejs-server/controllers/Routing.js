'use strict';

var url = require('url');

var Routing = require('./RoutingService');

module.exports.routeGET = function routeGET (req, res, next) {
  Routing.routeGET(req.swagger.params, res, next);
};
