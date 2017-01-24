'use strict';

exports.getSolution = function(args, res, next) {
  /**
   * Return the solution associated to the jobId
   * This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. 
   *
   * key String your API key
   * jobId String Request solution with jobId
   * returns Response
   **/
  var examples = {};
  examples['application/json'] = {
  "processing_time" : 123456789,
  "solution" : {
    "costs" : 123,
    "routes" : [ {
      "completion_time" : 123456789,
      "distance" : 123456789,
      "transport_time" : 123456789,
      "waiting_time" : 123456789,
      "activities" : [ {
        "distance" : 123456789,
        "waiting_time" : 123456789,
        "driving_time" : 123456789,
        "end_time" : 123456789,
        "load_before" : [ 123 ],
        "arr_time" : 123456789,
        "id" : "aeiou",
        "type" : "aeiou",
        "location_id" : "aeiou",
        "load_after" : [ 123 ]
      } ],
      "vehicle_id" : "aeiou"
    } ],
    "distance" : 123,
    "transport_time" : 123456789,
    "waiting_time" : 123456789,
    "no_vehicles" : 123,
    "time" : 123456789,
    "no_unassigned" : 123,
    "unassigned" : {
      "services" : [ "aeiou" ],
      "shipments" : [ "aeiou" ]
    },
    "max_operation_time" : 123456789
  },
  "copyrights" : [ "aeiou" ],
  "job_id" : "aeiou",
  "waiting_in_queue" : 123456789,
  "status" : "aeiou"
};
  if (Object.keys(examples).length > 0) {
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify(examples[Object.keys(examples)[0]] || {}, null, 2));
  } else {
    res.end();
  }
}

exports.postVrp = function(args, res, next) {
  /**
   * Solves vehicle routing problems
   * This endpoint for solving vehicle routing problems, i.e. traveling salesman or vehicle routing problems, and returns the solution. 
   *
   * key String your API key
   * body Request Request object that contains the problem to be solved
   * returns JobId
   **/
  var examples = {};
  examples['application/json'] = {
  "job_id" : "aeiou"
};
  if (Object.keys(examples).length > 0) {
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify(examples[Object.keys(examples)[0]] || {}, null, 2));
  } else {
    res.end();
  }
}

