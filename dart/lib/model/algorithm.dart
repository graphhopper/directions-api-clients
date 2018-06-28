part of openapi.api;

class Algorithm {
  
  String problemType = null;
  //enum problemTypeEnum {  min,  min-max,  };{
  
  String objective = null;
  //enum objectiveEnum {  transport_time,  completion_time,  };{
  Algorithm();

  @override
  String toString() {
    return 'Algorithm[problemType=$problemType, objective=$objective, ]';
  }

  Algorithm.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    problemType = json['problemType'];
    objective = json['objective'];
  }

  Map<String, dynamic> toJson() {
    return {
      'problemType': problemType,
      'objective': objective
    };
  }

  static List<Algorithm> listFromJson(List<dynamic> json) {
    return json == null ? new List<Algorithm>() : json.map((value) => new Algorithm.fromJson(value)).toList();
  }

  static Map<String, Algorithm> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Algorithm>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Algorithm.fromJson(value));
    }
    return map;
  }
}

