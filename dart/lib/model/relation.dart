part of openapi.api;

class Relation {
  /* identifier of relation */
  String type = null;
  /* An array of ids that should be related */
  List<String> ids = [];
  /* vehicle id */
  String vehicleId = null;
  Relation();

  @override
  String toString() {
    return 'Relation[type=$type, ids=$ids, vehicleId=$vehicleId, ]';
  }

  Relation.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    type = json['type'];
    ids = (json['ids'] as List).map((item) => item as String).toList();
    vehicleId = json['vehicleId'];
  }

  Map<String, dynamic> toJson() {
    return {
      'type': type,
      'ids': ids,
      'vehicleId': vehicleId
    };
  }

  static List<Relation> listFromJson(List<dynamic> json) {
    return json == null ? new List<Relation>() : json.map((value) => new Relation.fromJson(value)).toList();
  }

  static Map<String, Relation> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Relation>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Relation.fromJson(value));
    }
    return map;
  }
}

