part of openapi.api;

class RouteResponsePath {
  /* The total distance of the route, in meter */
  double distance = null;
  /* The total time of the route, in ms */
  int time = null;
  
  double ascend = null;
  /* The total descend (downhill) of the route, in meter */
  double descend = null;
  
  ResponseCoordinates points = null;
  /* Is true if the points are encoded, if not paths[0].points contains the geo json of the path (then order is lon,lat,elevation), which is easier to handle but consumes more bandwidth compared to encoded version */
  bool pointsEncoded = null;
  /* The bounding box of the route, format <br> minLon, minLat, maxLon, maxLat */
  List<double> bbox = [];
  
  ResponseCoordinates snappedWaypoints = null;
  
  ResponseInstructions instructions = null;
  
  Object details = null;
  RouteResponsePath();

  @override
  String toString() {
    return 'RouteResponsePath[distance=$distance, time=$time, ascend=$ascend, descend=$descend, points=$points, pointsEncoded=$pointsEncoded, bbox=$bbox, snappedWaypoints=$snappedWaypoints, instructions=$instructions, details=$details, ]';
  }

  RouteResponsePath.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    distance = json['distance'];
    time = json['time'];
    ascend = json['ascend'];
    descend = json['descend'];
    points = new ResponseCoordinates.fromJson(json['points']);
    pointsEncoded = json['pointsEncoded'];
    bbox = (json['bbox'] as List).map((item) => item as double).toList();
    snappedWaypoints = new ResponseCoordinates.fromJson(json['snappedWaypoints']);
    instructions = new ResponseInstructions.fromJson(json['instructions']);
    details = new Object.fromJson(json['details']);
  }

  Map<String, dynamic> toJson() {
    return {
      'distance': distance,
      'time': time,
      'ascend': ascend,
      'descend': descend,
      'points': points,
      'pointsEncoded': pointsEncoded,
      'bbox': bbox,
      'snappedWaypoints': snappedWaypoints,
      'instructions': instructions,
      'details': details
    };
  }

  static List<RouteResponsePath> listFromJson(List<dynamic> json) {
    return json == null ? new List<RouteResponsePath>() : json.map((value) => new RouteResponsePath.fromJson(value)).toList();
  }

  static Map<String, RouteResponsePath> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, RouteResponsePath>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new RouteResponsePath.fromJson(value));
    }
    return map;
  }
}

