package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.api.GeocodingApi;
import com.graphhopper.directions.api.client.model.GeocodingLocation;
import com.graphhopper.directions.api.client.model.GeocodingResponse;

/**
 * A simple geocoding request.
 */
public class GeocodingExample {
    public static void main(String[] args) {
        new GeocodingExample().start();
    }

    private void start() {
        GeocodingApi geocoding = new GeocodingApi();
        geocoding.setApiClient(GHApiUtil.createClient());
        try {
            GeocodingResponse geocodingResponse = geocoding.getGeocode("bautzen", "de", 5, false, false, null, null);
            GeocodingLocation loc0 = geocodingResponse.getHits().get(0);
            System.out.println(loc0.getPoint() + ", " + loc0.getName() + ", " + loc0.getCountry() + ", " + loc0.getState());
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }
    }
}
