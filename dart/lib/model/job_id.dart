part of swagger.api;

@Entity()
class JobId {
  /* unique id for your job/request with which you can fetch your solution */
  @Property(name: 'job_id')
  String jobId = null;
  
  JobId();

  @override
  String toString()  {
    return 'JobId[jobId=$jobId, ]';
  }
}

