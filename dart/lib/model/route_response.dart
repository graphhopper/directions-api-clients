part of openapi.api;

class RouteResponse {
  
  List<RouteResponsePath> paths = [];
  
  ResponseInfo info = null;
  RouteResponse();

  @override
  String toString() {
    return 'RouteResponse[paths=$paths, info=$info, ]';
  }

  RouteResponse.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    paths = RouteResponsePath.listFromJson(json['paths']);
    info = new ResponseInfo.fromJson(json['info']);
  }

  Map<String, dynamic> toJson() {
    return {
      'paths': paths,
      'info': info
    };
  }

  static List<RouteResponse> listFromJson(List<dynamic> json) {
    return json == null ? new List<RouteResponse>() : json.map((value) => new RouteResponse.fromJson(value)).toList();
  }

  static Map<String, RouteResponse> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, RouteResponse>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new RouteResponse.fromJson(value));
    }
    return map;
  }
}

