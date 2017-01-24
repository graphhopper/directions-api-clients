'use strict';

var url = require('url');

var Isochrone = require('./IsochroneService');

module.exports.isochroneGET = function isochroneGET (req, res, next) {
  Isochrone.isochroneGET(req.swagger.params, res, next);
};
