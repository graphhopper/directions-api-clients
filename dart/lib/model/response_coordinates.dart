part of openapi.api;

class ResponseCoordinates {
  
  ResponseCoordinatesArray coordinates = null;
  ResponseCoordinates();

  @override
  String toString() {
    return 'ResponseCoordinates[coordinates=$coordinates, ]';
  }

  ResponseCoordinates.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    coordinates = new ResponseCoordinatesArray.fromJson(json['coordinates']);
  }

  Map<String, dynamic> toJson() {
    return {
      'coordinates': coordinates
    };
  }

  static List<ResponseCoordinates> listFromJson(List<dynamic> json) {
    return json == null ? new List<ResponseCoordinates>() : json.map((value) => new ResponseCoordinates.fromJson(value)).toList();
  }

  static Map<String, ResponseCoordinates> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, ResponseCoordinates>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new ResponseCoordinates.fromJson(value));
    }
    return map;
  }
}

