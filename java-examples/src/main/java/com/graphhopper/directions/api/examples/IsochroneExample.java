package com.graphhopper.directions.api.examples;

import com.graphhopper.directions.api.client.api.IsochroneApi;
import com.graphhopper.directions.api.client.model.IsochroneResponse;
import com.graphhopper.directions.api.client.model.IsochroneResponsePolygon;
import com.graphhopper.directions.api.client.model.VehicleProfileId;

import java.math.BigDecimal;
import java.util.List;

/**
 * A simple Isochrone example
 */
public class IsochroneExample {
    public static void main(String[] args) {
        new IsochroneExample().start();
    }

    private void start() {
        IsochroneApi isochrone = new IsochroneApi();
        isochrone.setApiClient(GHApiUtil.createClient());
        try {
            // Please note: the request string for the point has the order "lat,lon" but the response contains
            // an array with the order [lon,lat]
            IsochroneResponse rsp = isochrone.getIsochrone("51.183728,14.42801", 10 * 60, -1, VehicleProfileId.CAR,
                    3, false, "fastest");
            final IsochroneResponsePolygon isochrone0 = rsp.getPolygons().get(0);
            List<List<BigDecimal>> exteriorRing = isochrone0.getGeometry().getCoordinates().get(0);
            System.out.println(exteriorRing);
            double lon0 = ((Number) exteriorRing.get(0).get(0)).doubleValue();
            double lat0 = ((Number) exteriorRing.get(0).get(1)).doubleValue();
            System.out.println("first coord " + lat0 + ", " + lon0);
        } catch (Exception ex) {
            throw new RuntimeException(ex);
        }
    }
}
