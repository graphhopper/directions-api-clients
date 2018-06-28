part of openapi.api;

class Route {
  /* id of vehicle that operates route */
  String vehicleId = null;
  /* distance of route in meter */
  int distance = null;
  /* transport time of route in seconds */
  int transportTime = null;
  /* completion time of route in seconds */
  int completionTime = null;
  /* waiting time of route in seconds */
  int waitingTime = null;
  /* array of activities */
  List<Activity> activities = [];
  /* array of route planning points */
  List<RoutePoint> points = [];
  Route();

  @override
  String toString() {
    return 'Route[vehicleId=$vehicleId, distance=$distance, transportTime=$transportTime, completionTime=$completionTime, waitingTime=$waitingTime, activities=$activities, points=$points, ]';
  }

  Route.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    vehicleId = json['vehicleId'];
    distance = json['distance'];
    transportTime = json['transportTime'];
    completionTime = json['completionTime'];
    waitingTime = json['waitingTime'];
    activities = Activity.listFromJson(json['activities']);
    points = RoutePoint.listFromJson(json['points']);
  }

  Map<String, dynamic> toJson() {
    return {
      'vehicleId': vehicleId,
      'distance': distance,
      'transportTime': transportTime,
      'completionTime': completionTime,
      'waitingTime': waitingTime,
      'activities': activities,
      'points': points
    };
  }

  static List<Route> listFromJson(List<dynamic> json) {
    return json == null ? new List<Route>() : json.map((value) => new Route.fromJson(value)).toList();
  }

  static Map<String, Route> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Route>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Route.fromJson(value));
    }
    return map;
  }
}

