part of openapi.api;

class IsochroneResponsePolygon {
  
  Object properties = null;
  
  String type = null;
  
  Object geometry = null;
  IsochroneResponsePolygon();

  @override
  String toString() {
    return 'IsochroneResponsePolygon[properties=$properties, type=$type, geometry=$geometry, ]';
  }

  IsochroneResponsePolygon.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    properties = new Object.fromJson(json['properties']);
    type = json['type'];
    geometry = new Object.fromJson(json['geometry']);
  }

  Map<String, dynamic> toJson() {
    return {
      'properties': properties,
      'type': type,
      'geometry': geometry
    };
  }

  static List<IsochroneResponsePolygon> listFromJson(List<dynamic> json) {
    return json == null ? new List<IsochroneResponsePolygon>() : json.map((value) => new IsochroneResponsePolygon.fromJson(value)).toList();
  }

  static Map<String, IsochroneResponsePolygon> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, IsochroneResponsePolygon>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new IsochroneResponsePolygon.fromJson(value));
    }
    return map;
  }
}

