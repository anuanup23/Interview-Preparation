package com.threading;

import lombok.NonNull;
import lombok.SneakyThrows;

public class Printer implements Runnable {
    private final Integer step;
    private final State state;
    private Integer currentValue;
    private final PrinterType currentPrinterType;
    private final PrinterType nextPrinterType;
    private final int maxValue;

    public Printer(@NonNull final Integer startValue, @NonNull final Integer step, @NonNull final State state,
                   @NonNull final PrinterType currentPrinterType, @NonNull final PrinterType nextPrinterType,
                   @NonNull Integer maxValue) {
        this.currentValue = startValue;
        this.step = step;
        this.state = state;
        this.currentPrinterType = currentPrinterType;
        this.nextPrinterType = nextPrinterType;
        this.maxValue = maxValue;
    }

    @SneakyThrows
    @Override
    public void run() {
//    	System.out.println(currentPrinterType);
//    	System.out.println(nextPrinterType);
        while (currentValue <= maxValue) {
            synchronized (state) { // here we share a common state object
                while (this.currentPrinterType != state.getNextToPrint()) {
                    state.wait();
                }
                System.out.println(currentPrinterType.toString() + ": " + currentValue);
                currentValue += step;
                state.setNextToPrint(this.nextPrinterType);
                state.notifyAll();
            }
        }
    }
}