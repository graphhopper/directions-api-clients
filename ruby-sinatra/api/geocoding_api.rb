require 'json'


MyApp.add_route('GET', '/api/1/geocode', {
  "resourcePath" => "/Geocoding",
  "summary" => "Execute a Geocoding request",
  "nickname" => "geocode_get", 
  "responseClass" => "GeocodingResponse", 
  "endpoint" => "/geocode", 
  "notes" => "This endpoint provides forward and reverse geocoding. For more details, review the official documentation at: https://graphhopper.com/api/1/docs/geocoding/ ",
  "parameters" => [
    {
      "name" => "q",
      "description" => "If you do forward geocoding, then this would be a textual description of the address you are looking for",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "locale",
      "description" => "Display the search results for the specified locale. Currently French (fr), English (en), German (de) and Italian (it) are supported. If the locale wasn&#39;t found the default (en) is used.",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "limit",
      "description" => "Specify the maximum number of returned results",
      "dataType" => "int",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "reverse",
      "description" => "Set to true to do a reverse Geocoding request, see point parameter",
      "dataType" => "boolean",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "point",
      "description" => "The location bias in the format &#39;latitude,longitude&#39; e.g. point&#x3D;45.93272,11.58803",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "provider",
      "description" => "Can be either, default, nominatim, opencagedata",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    {
      "name" => "key",
      "description" => "Get your key at graphhopper.com",
      "dataType" => "string",
      "allowableValues" => "",
      "paramType" => "query",
    },
    ]}) do
  cross_origin
  # the guts live here

  {"message" => "yes, it worked"}.to_json
end

