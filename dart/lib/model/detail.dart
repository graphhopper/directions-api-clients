part of openapi.api;

class Detail {
  /* id of unassigned service/shipment */
  String id = null;
  /* reason code */
  int code = null;
  /* human readable reason */
  String reason = null;
  Detail();

  @override
  String toString() {
    return 'Detail[id=$id, code=$code, reason=$reason, ]';
  }

  Detail.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    id = json['id'];
    code = json['code'];
    reason = json['reason'];
  }

  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'code': code,
      'reason': reason
    };
  }

  static List<Detail> listFromJson(List<dynamic> json) {
    return json == null ? new List<Detail>() : json.map((value) => new Detail.fromJson(value)).toList();
  }

  static Map<String, Detail> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Detail>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Detail.fromJson(value));
    }
    return map;
  }
}

