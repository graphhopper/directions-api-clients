part of swagger.api;

@Entity()
class GeocodingLocation {
  
  @Property(name: 'point')
  GeocodingPoint point = null;
  
/* OSM Id */
  @Property(name: 'osm_id')
  String osmId = null;
  
/* N = node, R = relation, W = way */
  @Property(name: 'osm_type')
  String osmType = null;
  
/* The osm key of the result like `place` or `amenity` */
  @Property(name: 'osm_key')
  String osmKey = null;
  

  @Property(name: 'name')
  String name = null;
  

  @Property(name: 'country')
  String country = null;
  

  @Property(name: 'city')
  String city = null;
  

  @Property(name: 'state')
  String state = null;
  

  @Property(name: 'street')
  String street = null;
  

  @Property(name: 'housenumber')
  String housenumber = null;
  

  @Property(name: 'postcode')
  String postcode = null;
  
  GeocodingLocation();

  @override
  String toString()  {
    return 'GeocodingLocation[point=$point, osmId=$osmId, osmType=$osmType, osmKey=$osmKey, name=$name, country=$country, city=$city, state=$state, street=$street, housenumber=$housenumber, postcode=$postcode, ]';
  }
}

