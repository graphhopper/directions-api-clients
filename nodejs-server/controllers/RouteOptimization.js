'use strict';

var url = require('url');

var RouteOptimization = require('./RouteOptimizationService');

module.exports.getSolution = function getSolution (req, res, next) {
  RouteOptimization.getSolution(req.swagger.params, res, next);
};

module.exports.postVrp = function postVrp (req, res, next) {
  RouteOptimization.postVrp(req.swagger.params, res, next);
};
