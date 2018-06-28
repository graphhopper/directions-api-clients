part of openapi.api;

class Routing {
  /* indicates whether solution should come with route geometries */
  bool calcPoints = null;
  /* indicates whether historical traffic information should be considered */
  bool considerTraffic = null;
  /* specifies the data provider */
  String networkDataProvider = null;
  //enum networkDataProviderEnum {  openstreetmap,  tomtom,  };{
  /* indicates whether matrix calculation should fail fast when points cannot be connected */
  bool failFast = null;
  Routing();

  @override
  String toString() {
    return 'Routing[calcPoints=$calcPoints, considerTraffic=$considerTraffic, networkDataProvider=$networkDataProvider, failFast=$failFast, ]';
  }

  Routing.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    calcPoints = json['calcPoints'];
    considerTraffic = json['considerTraffic'];
    networkDataProvider = json['networkDataProvider'];
    failFast = json['failFast'];
  }

  Map<String, dynamic> toJson() {
    return {
      'calcPoints': calcPoints,
      'considerTraffic': considerTraffic,
      'networkDataProvider': networkDataProvider,
      'failFast': failFast
    };
  }

  static List<Routing> listFromJson(List<dynamic> json) {
    return json == null ? new List<Routing>() : json.map((value) => new Routing.fromJson(value)).toList();
  }

  static Map<String, Routing> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Routing>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Routing.fromJson(value));
    }
    return map;
  }
}

