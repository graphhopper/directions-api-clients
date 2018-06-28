part of openapi.api;

class CostMatrix {
  /* type of cost matrix, currently default or google are supported */
  String type = null;
  //enum typeEnum {  default,  google,  };{
  /* URL of matrix service */
  String url = null;
  
  List<String> locationIds = [];
  /* JSON data of matrix response */
  Object data = null;
  /* vehicle profile or empty if catch all fallback */
  String profile = null;
  CostMatrix();

  @override
  String toString() {
    return 'CostMatrix[type=$type, url=$url, locationIds=$locationIds, data=$data, profile=$profile, ]';
  }

  CostMatrix.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    type = json['type'];
    url = json['url'];
    locationIds = (json['locationIds'] as List).map((item) => item as String).toList();
    data = new Object.fromJson(json['data']);
    profile = json['profile'];
  }

  Map<String, dynamic> toJson() {
    return {
      'type': type,
      'url': url,
      'locationIds': locationIds,
      'data': data,
      'profile': profile
    };
  }

  static List<CostMatrix> listFromJson(List<dynamic> json) {
    return json == null ? new List<CostMatrix>() : json.map((value) => new CostMatrix.fromJson(value)).toList();
  }

  static Map<String, CostMatrix> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, CostMatrix>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new CostMatrix.fromJson(value));
    }
    return map;
  }
}

