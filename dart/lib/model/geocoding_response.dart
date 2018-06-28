part of openapi.api;

class GeocodingResponse {
  
  List<GeocodingLocation> hits = [];
  
  String locale = null;
  GeocodingResponse();

  @override
  String toString() {
    return 'GeocodingResponse[hits=$hits, locale=$locale, ]';
  }

  GeocodingResponse.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    hits = GeocodingLocation.listFromJson(json['hits']);
    locale = json['locale'];
  }

  Map<String, dynamic> toJson() {
    return {
      'hits': hits,
      'locale': locale
    };
  }

  static List<GeocodingResponse> listFromJson(List<dynamic> json) {
    return json == null ? new List<GeocodingResponse>() : json.map((value) => new GeocodingResponse.fromJson(value)).toList();
  }

  static Map<String, GeocodingResponse> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, GeocodingResponse>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new GeocodingResponse.fromJson(value));
    }
    return map;
  }
}

