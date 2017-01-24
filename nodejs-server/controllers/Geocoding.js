'use strict';

var url = require('url');

var Geocoding = require('./GeocodingService');

module.exports.geocodeGET = function geocodeGET (req, res, next) {
  Geocoding.geocodeGET(req.swagger.params, res, next);
};
