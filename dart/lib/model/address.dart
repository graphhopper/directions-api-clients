part of openapi.api;

class Address {
  /* Unique identifier of location */
  String locationId = null;
  /* name of location, e.g. street name plus house number */
  String name = null;
  /* longitude */
  double lon = null;
  /* latitude */
  double lat = null;
  /* Optional parameter. Specifies a hint for each address to better snap the coordinates (lon,lat) to road network. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. */
  String streetHint = null;
  Address();

  @override
  String toString() {
    return 'Address[locationId=$locationId, name=$name, lon=$lon, lat=$lat, streetHint=$streetHint, ]';
  }

  Address.fromJson(Map<String, dynamic> json) {
    if (json == null) return;
    locationId = json['locationId'];
    name = json['name'];
    lon = json['lon'];
    lat = json['lat'];
    streetHint = json['streetHint'];
  }

  Map<String, dynamic> toJson() {
    return {
      'locationId': locationId,
      'name': name,
      'lon': lon,
      'lat': lat,
      'streetHint': streetHint
    };
  }

  static List<Address> listFromJson(List<dynamic> json) {
    return json == null ? new List<Address>() : json.map((value) => new Address.fromJson(value)).toList();
  }

  static Map<String, Address> mapFromJson(Map<String, Map<String, dynamic>> json) {
    var map = new Map<String, Address>();
    if (json != null && json.length > 0) {
      json.forEach((String key, Map<String, dynamic> value) => map[key] = new Address.fromJson(value));
    }
    return map;
  }
}

