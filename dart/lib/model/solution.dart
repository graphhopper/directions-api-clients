part of openapi.api;

class Solution {
  /* overall costs of solution */
  int costs = null;
  /* overall travel distance in meters */
  int distance = null;
  /* overall transport time in seconds */
  int time = null;
  /* overall transport time in seconds */
  int transportTime = null;
  /* operation time of the longest route in seconds */
  int maxOperationTime = null;
  /* total waiting time in seconds */
  int waitingTime = null;
  /* number of employed vehicles */
  int noVehicles = null;
  /* number of jobs that could not be assigned to final solution */
  int noUnassigned = null;
  /* An array of routes */
  List<Route> routes = [];
  
  Object unassigned = null;
  Solution();

  @override
  String toString() {
    return 'Solution[costs=$costs, distance=$distance, time=$time, transportTime=$transportTime, maxOperationTime=$maxOperationTime, waitingTime=$waitingTime, noVehicles=$noVehicles, noUnassigned=$noUnassigned, routes=$routes, unassigned=$unassigned, ]';
  }

  Solution.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    costs = json['costs'];
    distance = json['distance'];
    time = json['time'];
    transportTime = json['transportTime'];
    maxOperationTime = json['maxOperationTime'];
    waitingTime = json['waitingTime'];
    noVehicles = json['noVehicles'];
    noUnassigned = json['noUnassigned'];
    routes = Route.listFromJson(json['routes']);
    unassigned = new Object.fromJson(json['unassigned']);
  }

  Map<String, dynamic> toJson() {
    return {
      'costs': costs,
      'distance': distance,
      'time': time,
      'transportTime': transportTime,
      'maxOperationTime': maxOperationTime,
      'waitingTime': waitingTime,
      'noVehicles': noVehicles,
      'noUnassigned': noUnassigned,
      'routes': routes,
      'unassigned': unassigned
    };
  }

  static List<Solution> listFromJson(List<dynamic> json) {
    return json == null ? new List<Solution>() : json.map((value) => new Solution.fromJson(value)).toList();
  }

  static Map<String, Solution> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Solution>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Solution.fromJson(value));
    }
    return map;
  }
}

