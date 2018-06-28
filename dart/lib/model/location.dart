part of openapi.api;

class Location {
  /* longitude */
  double lon = null;
  /* latitude */
  double lat = null;
  Location();

  @override
  String toString() {
    return 'Location[lon=$lon, lat=$lat, ]';
  }

  Location.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    lon = json['lon'];
    lat = json['lat'];
  }

  Map<String, dynamic> toJson() {
    return {
      'lon': lon,
      'lat': lat
    };
  }

  static List<Location> listFromJson(List<dynamic> json) {
    return json == null ? new List<Location>() : json.map((value) => new Location.fromJson(value)).toList();
  }

  static Map<String, Location> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Location>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Location.fromJson(value));
    }
    return map;
  }
}

