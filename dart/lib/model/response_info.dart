part of openapi.api;

class ResponseInfo {
  
  List<String> copyrights = [];
  
  double took = null;
  ResponseInfo();

  @override
  String toString() {
    return 'ResponseInfo[copyrights=$copyrights, took=$took, ]';
  }

  ResponseInfo.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    copyrights = (json['copyrights'] as List).map((item) => item as String).toList();
    took = json['took'];
  }

  Map<String, dynamic> toJson() {
    return {
      'copyrights': copyrights,
      'took': took
    };
  }

  static List<ResponseInfo> listFromJson(List<dynamic> json) {
    return json == null ? new List<ResponseInfo>() : json.map((value) => new ResponseInfo.fromJson(value)).toList();
  }

  static Map<String, ResponseInfo> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, ResponseInfo>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new ResponseInfo.fromJson(value));
    }
    return map;
  }
}

