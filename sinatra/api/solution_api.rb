require 'json'


MyApp.add_route('GET', '/api/1/vrp/solution/{jobId}', {
  "resourcePath" => "/Solution",
  "summary" => "Return the solution associated to the jobId",
  "nickname" => "get_solution", 
  "responseClass" => "Response", 
  "endpoint" => "/vrp/solution/{jobId}", 
  "notes" => "This endpoint returns the solution of a large problems. You can fetch it with the job_id, you have been sent. ",
  "parameters" => [
    {
      "name" => "key",
      "description" => "your API key",
      "dataType" => "string",
      "paramType" => "query",
      
      "allowableValues" => "",
      
    },
    {
      "name" => "job_id",
      "description" => "Request solution with jobId",
      "dataType" => "string",
      "paramType" => "path",
    },
    ]}) do
  cross_origin
  # the guts live here

  {"message" => "yes, it worked"}.to_json
end

