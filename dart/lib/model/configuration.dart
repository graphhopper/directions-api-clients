part of openapi.api;

class Configuration {
  
  Routing routing = null;
  Configuration();

  @override
  String toString() {
    return 'Configuration[routing=$routing, ]';
  }

  Configuration.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    routing = new Routing.fromJson(json['routing']);
  }

  Map<String, dynamic> toJson() {
    return {
      'routing': routing
    };
  }

  static List<Configuration> listFromJson(List<dynamic> json) {
    return json == null ? new List<Configuration>() : json.map((value) => new Configuration.fromJson(value)).toList();
  }

  static Map<String, Configuration> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Configuration>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Configuration.fromJson(value));
    }
    return map;
  }
}

