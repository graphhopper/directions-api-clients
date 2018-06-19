part of swagger.api;

@Entity()
class Address {
  /* Unique identifier of location */
  @Property(name: 'location_id')
  String locationId = null;
  
/* name of location, e.g. street name plus house number */
  @Property(name: 'name')
  String name = null;
  
/* longitude */
  @Property(name: 'lon')
  double lon = null;
  
/* latitude */
  @Property(name: 'lat')
  double lat = null;
  
/* Optional parameter. Specifies a hint for each address to better snap the coordinates (lon,lat) to road network. E.g. if there is an address or house with two or more neighboring streets you can control for which street the closest location is looked up. */
  @Property(name: 'street_hint')
  String streetHint = null;
  
  Address();

  @override
  String toString()  {
    return 'Address[locationId=$locationId, name=$name, lon=$lon, lat=$lat, streetHint=$streetHint, ]';
  }
}

