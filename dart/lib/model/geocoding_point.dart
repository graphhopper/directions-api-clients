part of openapi.api;

class GeocodingPoint {
  /* Latitude */
  double lat = null;
  /* Longitude */
  double lng = null;
  GeocodingPoint();

  @override
  String toString() {
    return 'GeocodingPoint[lat=$lat, lng=$lng, ]';
  }

  GeocodingPoint.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    lat = json['lat'];
    lng = json['lng'];
  }

  Map<String, dynamic> toJson() {
    return {
      'lat': lat,
      'lng': lng
    };
  }

  static List<GeocodingPoint> listFromJson(List<dynamic> json) {
    return json == null ? new List<GeocodingPoint>() : json.map((value) => new GeocodingPoint.fromJson(value)).toList();
  }

  static Map<String, GeocodingPoint> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, GeocodingPoint>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new GeocodingPoint.fromJson(value));
    }
    return map;
  }
}

