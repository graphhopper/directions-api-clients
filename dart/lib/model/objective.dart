part of openapi.api;

class Objective {
  /* type of objective function, i.e. min or min-max  */
  String type = null;
  //enum typeEnum {  min,  min-max,  };{
  /* objective function value */
  String value = null;
  //enum valueEnum {  completion_time,  transport_time,  vehicles,  };{
  Objective();

  @override
  String toString() {
    return 'Objective[type=$type, value=$value, ]';
  }

  Objective.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    type = json['type'];
    value = json['value'];
  }

  Map<String, dynamic> toJson() {
    return {
      'type': type,
      'value': value
    };
  }

  static List<Objective> listFromJson(List<dynamic> json) {
    return json == null ? new List<Objective>() : json.map((value) => new Objective.fromJson(value)).toList();
  }

  static Map<String, Objective> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Objective>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Objective.fromJson(value));
    }
    return map;
  }
}

