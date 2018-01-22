part of swagger.api;

@Entity()
class Relation {
  /* identifier of relation */
  @Property(name: 'type')
  String type = null;
  
/* An array of ids that should be related */
  @Property(name: 'ids')
  List<String> ids = [];
  
/* vehicle id */
  @Property(name: 'vehicle_id')
  String vehicleId = null;
  
  Relation();

  @override
  String toString()  {
    return 'Relation[type=$type, ids=$ids, vehicleId=$vehicleId, ]';
  }
}

