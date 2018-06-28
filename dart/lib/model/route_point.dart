part of openapi.api;

class RoutePoint {
  
  String type = null;
  
  List<Object> coordinates = [];
  RoutePoint();

  @override
  String toString() {
    return 'RoutePoint[type=$type, coordinates=$coordinates, ]';
  }

  RoutePoint.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    type = json['type'];
    coordinates = Object.listFromJson(json['coordinates']);
  }

  Map<String, dynamic> toJson() {
    return {
      'type': type,
      'coordinates': coordinates
    };
  }

  static List<RoutePoint> listFromJson(List<dynamic> json) {
    return json == null ? new List<RoutePoint>() : json.map((value) => new RoutePoint.fromJson(value)).toList();
  }

  static Map<String, RoutePoint> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, RoutePoint>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new RoutePoint.fromJson(value));
    }
    return map;
  }
}

