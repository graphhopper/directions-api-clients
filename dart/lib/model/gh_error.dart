part of openapi.api;

class GHError {
  
  int code = null;
  
  String message = null;
  
  List<Object> hints = [];
  GHError();

  @override
  String toString() {
    return 'GHError[code=$code, message=$message, hints=$hints, ]';
  }

  GHError.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    code = json['code'];
    message = json['message'];
    hints = Object.listFromJson(json['hints']);
  }

  Map<String, dynamic> toJson() {
    return {
      'code': code,
      'message': message,
      'hints': hints
    };
  }

  static List<GHError> listFromJson(List<dynamic> json) {
    return json == null ? new List<GHError>() : json.map((value) => new GHError.fromJson(value)).toList();
  }

  static Map<String, GHError> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, GHError>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new GHError.fromJson(value));
    }
    return map;
  }
}

