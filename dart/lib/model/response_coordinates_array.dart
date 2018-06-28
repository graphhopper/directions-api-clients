part of openapi.api;

class ResponseCoordinatesArray {
  ResponseCoordinatesArray();

  @override
  String toString() {
    return 'ResponseCoordinatesArray[]';
  }

  ResponseCoordinatesArray.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
  }

  Map<String, dynamic> toJson() {
    return {
    };
  }

  static List<ResponseCoordinatesArray> listFromJson(List<dynamic> json) {
    return json == null ? new List<ResponseCoordinatesArray>() : json.map((value) => new ResponseCoordinatesArray.fromJson(value)).toList();
  }

  static Map<String, ResponseCoordinatesArray> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, ResponseCoordinatesArray>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new ResponseCoordinatesArray.fromJson(value));
    }
    return map;
  }
}

