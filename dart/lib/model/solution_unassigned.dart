part of swagger.api;

@Entity()
class SolutionUnassigned {
  /* An array of ids of unassigned services */
  @Property(name: 'services')
  List<String> services = [];
  
/* An array of ids of unassigned shipments */
  @Property(name: 'shipments')
  List<String> shipments = [];
  
/* An array of ids of unassigned breaks */
  @Property(name: 'breaks')
  List<String> breaks = [];
  
/* An array of details, i.e. reason for unassigned services or shipments */
  @Property(name: 'details')
  List<Detail> details = [];
  
  SolutionUnassigned();

  @override
  String toString()  {
    return 'SolutionUnassigned[services=$services, shipments=$shipments, breaks=$breaks, details=$details, ]';
  }
}

