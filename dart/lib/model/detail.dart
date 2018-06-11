part of swagger.api;

@Entity()
class Detail {
  /* id of unassigned service/shipment */
  @Property(name: 'id')
  String id = null;
  
/* reason code */
  @Property(name: 'code')
  int code = null;
  
/* human readable reason */
  @Property(name: 'reason')
  String reason = null;
  
  Detail();

  @override
  String toString()  {
    return 'Detail[id=$id, code=$code, reason=$reason, ]';
  }
}

