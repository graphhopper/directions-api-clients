part of openapi.api;

class ResponseInstructions {
  ResponseInstructions();

  @override
  String toString() {
    return 'ResponseInstructions[]';
  }

  ResponseInstructions.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
  }

  Map<String, dynamic> toJson() {
    return {
    };
  }

  static List<ResponseInstructions> listFromJson(List<dynamic> json) {
    return json == null ? new List<ResponseInstructions>() : json.map((value) => new ResponseInstructions.fromJson(value)).toList();
  }

  static Map<String, ResponseInstructions> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, ResponseInstructions>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new ResponseInstructions.fromJson(value));
    }
    return map;
  }
}

