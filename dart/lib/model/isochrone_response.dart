part of openapi.api;

class IsochroneResponse {
  
  List<IsochroneResponsePolygon> polygons = [];
  
  List<String> copyrights = [];
  IsochroneResponse();

  @override
  String toString() {
    return 'IsochroneResponse[polygons=$polygons, copyrights=$copyrights, ]';
  }

  IsochroneResponse.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    polygons = IsochroneResponsePolygon.listFromJson(json['polygons']);
    copyrights = (json['copyrights'] as List).map((item) => item as String).toList();
  }

  Map<String, dynamic> toJson() {
    return {
      'polygons': polygons,
      'copyrights': copyrights
    };
  }

  static List<IsochroneResponse> listFromJson(List<dynamic> json) {
    return json == null ? new List<IsochroneResponse>() : json.map((value) => new IsochroneResponse.fromJson(value)).toList();
  }

  static Map<String, IsochroneResponse> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, IsochroneResponse>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new IsochroneResponse.fromJson(value));
    }
    return map;
  }
}

