import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Quiz extends JFrame implements ActionListener {
    private JLabel questionLabel;
    private JRadioButton[] options;
    private ButtonGroup optionGroup;
    private JButton submitButton, nextButton, finishButton;
    private int currentQuestionIndex = 0;
    private int score = 0;

    private String[] questions = {
            "Which is the largest planet in our solar system?",
            "What is the capital of France?",
            "Which element has the chemical symbol 'O'?",
            "What is the currency of Japan?"
    };

    private String[][] optionsData = {
            {"Earth", "Jupiter", "Mars", "Saturn"},
            {"Berlin", "Madrid", "Paris", "Lisbon"},
            {"Oxygen", "Hydrogen", "Nitrogen", "Carbon"},
            {"Yen", "Won", "Dollar", "Euro"}
    };

    private int[] answers = {1, 2, 0, 0};

    public Quiz() {
        setTitle("Quiz Application");
        setSize(500, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        questionLabel = new JLabel();
        questionLabel.setFont(new Font("Arial", Font.BOLD, 16));
        questionLabel.setHorizontalAlignment(SwingConstants.CENTER);
        add(questionLabel, BorderLayout.NORTH);

        options = new JRadioButton[4];
        optionGroup = new ButtonGroup();
        JPanel optionsPanel = new JPanel(new GridLayout(4, 1));
        for (int i = 0; i < 4; i++) {
            options[i] = new JRadioButton();
            optionGroup.add(options[i]);
            optionsPanel.add(options[i]);
        }
        add(optionsPanel, BorderLayout.CENTER);

        JPanel buttonPanel = new JPanel();
        submitButton = new JButton("Submit");
        submitButton.addActionListener(this);
        buttonPanel.add(submitButton);

        nextButton = new JButton("Next");
        nextButton.addActionListener(this);
        nextButton.setEnabled(false);
        buttonPanel.add(nextButton);

        finishButton = new JButton("Finish");
        finishButton.addActionListener(this);
        finishButton.setEnabled(false);
        buttonPanel.add(finishButton);

        add(buttonPanel, BorderLayout.SOUTH);

        loadQuestion();
        setVisible(true);
    }

    private void loadQuestion() {
        questionLabel.setText("Q" + (currentQuestionIndex + 1) + ": " + questions[currentQuestionIndex]);
        for (int i = 0; i < 4; i++) {
            options[i].setText(optionsData[currentQuestionIndex][i]);
            options[i].setSelected(false);
        }

        nextButton.setEnabled(false);
        submitButton.setEnabled(true);
        if (currentQuestionIndex == questions.length - 1) {
            finishButton.setEnabled(true);
            nextButton.setEnabled(false);
        }
    }

    private void checkAnswer() {
        int selectedOption = -1;
        for (int i = 0; i < options.length; i++) {
            if (options[i].isSelected()) {
                selectedOption = i;
                break;
            }
        }

        if (selectedOption == answers[currentQuestionIndex]) {
            score++;
        }
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == submitButton) {
            checkAnswer();
            submitButton.setEnabled(false);
            nextButton.setEnabled(currentQuestionIndex < questions.length - 1);
        } else if (e.getSource() == nextButton) {
            currentQuestionIndex++;
            loadQuestion();
        } else if (e.getSource() == finishButton) {
            JOptionPane.showMessageDialog(this, "Quiz Finished! Your score: " + score + "/" + questions.length);
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Quiz::new);
    }
}