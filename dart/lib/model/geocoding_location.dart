part of openapi.api;

class GeocodingLocation {
  
  GeocodingPoint point = null;
  /* OSM Id */
  String osmId = null;
  /* N = node, R = relation, W = way */
  String osmType = null;
  /* The osm key of the result like `place` or `amenity` */
  String osmKey = null;
  
  String name = null;
  
  String country = null;
  
  String city = null;
  
  String state = null;
  
  String street = null;
  
  String housenumber = null;
  
  String postcode = null;
  GeocodingLocation();

  @override
  String toString() {
    return 'GeocodingLocation[point=$point, osmId=$osmId, osmType=$osmType, osmKey=$osmKey, name=$name, country=$country, city=$city, state=$state, street=$street, housenumber=$housenumber, postcode=$postcode, ]';
  }

  GeocodingLocation.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    point = new GeocodingPoint.fromJson(json['point']);
    osmId = json['osmId'];
    osmType = json['osmType'];
    osmKey = json['osmKey'];
    name = json['name'];
    country = json['country'];
    city = json['city'];
    state = json['state'];
    street = json['street'];
    housenumber = json['housenumber'];
    postcode = json['postcode'];
  }

  Map<String, dynamic> toJson() {
    return {
      'point': point,
      'osmId': osmId,
      'osmType': osmType,
      'osmKey': osmKey,
      'name': name,
      'country': country,
      'city': city,
      'state': state,
      'street': street,
      'housenumber': housenumber,
      'postcode': postcode
    };
  }

  static List<GeocodingLocation> listFromJson(List<dynamic> json) {
    return json == null ? new List<GeocodingLocation>() : json.map((value) => new GeocodingLocation.fromJson(value)).toList();
  }

  static Map<String, GeocodingLocation> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, GeocodingLocation>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new GeocodingLocation.fromJson(value));
    }
    return map;
  }
}

