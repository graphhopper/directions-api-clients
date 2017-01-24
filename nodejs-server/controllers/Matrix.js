'use strict';

var url = require('url');

var Matrix = require('./MatrixService');

module.exports.matrixGET = function matrixGET (req, res, next) {
  Matrix.matrixGET(req.swagger.params, res, next);
};

module.exports.matrixPOST = function matrixPOST (req, res, next) {
  Matrix.matrixPOST(req.swagger.params, res, next);
};
